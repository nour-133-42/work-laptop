import { Component, ChangeDetectionStrategy, inject } from '@angular/core';
import { AuthService } from '../../core/services/auth.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-dashboard.component',
  imports: [],
  templateUrl: './dashboard.component.html',
  styleUrl: './dashboard.component.scss',
  changeDetection: ChangeDetectionStrategy.OnPush,
})
export class DashboardComponent {
  private auth = inject(AuthService);
  private router = inject(Router);

  get username(): string | null {
    return this.auth.getUsername();
  }

  logout(): void {
    this.auth.logout();
    this.router.navigate(['/login']);
  }
}
