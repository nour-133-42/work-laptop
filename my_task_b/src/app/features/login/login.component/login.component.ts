import { Component, ChangeDetectionStrategy, ChangeDetectorRef, OnDestroy } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { inject } from '@angular/core';
import { Router } from '@angular/router';
import { AuthService } from '../../../core/services/auth.service';
import { Subject } from 'rxjs';
import { takeUntil } from 'rxjs/operators';

@Component({
  selector: 'app-login.component',
  imports: [FormsModule],
  templateUrl: './login.component.html',
  styleUrl: './login.component.scss',
  changeDetection: ChangeDetectionStrategy.OnPush,
})
export class LoginComponent implements OnDestroy {
  private router = inject(Router);
  private auth = inject(AuthService);
  private cdr = inject(ChangeDetectorRef);
  private destroy$ = new Subject<void>();

  username = '';
  password = '';
  loading = false;
  error: string | null = null;

  ngOnDestroy(): void {
    this.destroy$.next();
    this.destroy$.complete();
  }

  submit(): void {
    if (!this.username || !this.password) {
      this.error = 'Username and password required';
      this.cdr.markForCheck();
      return;
    }

    this.error = null;
    this.loading = true;
    this.cdr.markForCheck();

    this.auth
      .login(this.username, this.password)
      .pipe(takeUntil(this.destroy$))
      .subscribe({
        next: () => {
          this.loading = false;
          this.cdr.markForCheck();
          this.router.navigate(['/dashboard']);
        },
        error: (err: any) => {
          this.loading = false;
          this.error = err?.message || 'Login failed. Please try again.';
          this.cdr.markForCheck();
        },
      });
  }
}
