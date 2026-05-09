import { CanActivateFn, Router } from '@angular/router';
import { inject } from '@angular/core';
import { AuthService } from '../services/auth.service';

/**
 * Guard that prevents logged-in users from accessing the login page.
 * Redirects authenticated users to dashboard.
 */
export const noAuthGuard: CanActivateFn = (route, state) => {
  const authService = inject(AuthService);
  const router = inject(Router);

  // If user is already logged in, redirect to dashboard
  if (authService.islogin()) {
    router.navigate(['/dashboard']);
    return false;
  }

  // Allow access to login page if not logged in
  return true;
};
