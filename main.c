/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* test.c                                             :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: suedasarican <student.42istanbul.com.tr>   +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/03/02 14:00:00 by suedasarican      #+#    #+#             */
/* Updated: 2026/03/02 14:00:00 by suedasarican     ###   ########.fr       */
/* */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

/* Renk Kodları (Çıktıyı güzelleştirmek için) */
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RESET   "\033[0m"

/* Test sayacı ve hata sayacı */
int g_tests = 0;
int g_errors = 0;

/* Yardımcı Fonksiyon: Sonuçları Kıyaslar */
void	check(int ret_ft, int ret_orig)
{
	g_tests++;
	if (ret_ft == ret_orig)
		printf("\t" GREEN "[OK] Return: %d" RESET "\n", ret_ft);
	else
	{
		printf("\t" RED "[KO] BEKLENEN: %d, ALINAN: %d" RESET "\n", ret_orig, ret_ft);
		g_errors++;
	}
	printf("--------------------------------------------------\n");
}

int	main(void)
{
	int		ft;
	int		orig;
	char	*str_null;
	void	*ptr_null;
	int		num;

	str_null = NULL;
	ptr_null = NULL;
	num = 42;

	printf(YELLOW "\n=== BASİT KARAKTER TESTLERİ (%%c) ===\n" RESET);
	
	// Test 1: Normal Karakter
	printf("TEST 1: 'A' Harfi\n");
	ft = ft_printf("Mine: %c\n", 'A');
	orig = printf("Orig: %c\n", 'A');
	check(ft, orig);

	// Test 2: Rakam Karakteri
	printf("TEST 2: '9' Rakamı\n");
	ft = ft_printf("Mine: %c\n", '9');
	orig = printf("Orig: %c\n", '9');
	check(ft, orig);

	printf(YELLOW "\n=== STRING TESTLERİ (%%s) ===\n" RESET);

	// Test 3: Normal String
	printf("TEST 3: Merhaba Dünya\n");
	ft = ft_printf("Mine: %s\n", "Merhaba 42");
	orig = printf("Orig: %s\n", "Merhaba 42");
	check(ft, orig);

	// Test 4: NULL String (Kritik!)
	printf("TEST 4: NULL String\n");
	ft = ft_printf("Mine: %s\n", str_null);
	orig = printf("Orig: %s\n", str_null);
	check(ft, orig);

	// Test 5: Boş String
	printf("TEST 5: Boş String (Empty)\n");
	ft = ft_printf("Mine: %s\n", "");
	orig = printf("Orig: %s\n", "");
	check(ft, orig);

	printf(YELLOW "\n=== SAYI TESTLERİ (%%d, %%i) ===\n" RESET);

	// Test 6: Pozitif Sayı
	printf("TEST 6: 42 Sayısı\n");
	ft = ft_printf("Mine: %d\n", 42);
	orig = printf("Orig: %d\n", 42);
	check(ft, orig);

	// Test 7: Negatif Sayı
	printf("TEST 7: -42 Sayısı\n");
	ft = ft_printf("Mine: %i\n", -42);
	orig = printf("Orig: %i\n", -42);
	check(ft, orig);

	// Test 8: Sıfır
	printf("TEST 8: Sıfır\n");
	ft = ft_printf("Mine: %d\n", 0);
	orig = printf("Orig: %d\n", 0);
	check(ft, orig);

	// Test 9: INT_MIN (En Küçük Integer)
	printf("TEST 9: INT_MIN\n");
	ft = ft_printf("Mine: %d\n", INT_MIN);
	orig = printf("Orig: %d\n", INT_MIN);
	check(ft, orig);

	// Test 10: INT_MAX (En Büyük Integer)
	printf("TEST 10: INT_MAX\n");
	ft = ft_printf("Mine: %d\n", INT_MAX);
	orig = printf("Orig: %d\n", INT_MAX);
	check(ft, orig);

	printf(YELLOW "\n=== UNSIGNED TESTLERİ (%%u) ===\n" RESET);

	// Test 11: UINT_MAX
	printf("TEST 11: UINT_MAX\n");
	ft = ft_printf("Mine: %u\n", UINT_MAX);
	orig = printf("Orig: %u\n", UINT_MAX);
	check(ft, orig);

	// Test 12: Negatif Giriş (Overflow)
	printf("TEST 12: Negatif Cast (-1)\n");
	ft = ft_printf("Mine: %u\n", -1);
	orig = printf("Orig: %u\n", -1);
	check(ft, orig);

	printf(YELLOW "\n=== HEXADECIMAL TESTLERİ (%%x, %%X) ===\n" RESET);

	// Test 13: Küçük Hex
	printf("TEST 13: 255 (ff)\n");
	ft = ft_printf("Mine: %x\n", 255);
	orig = printf("Orig: %x\n", 255);
	check(ft, orig);

	// Test 14: Büyük Hex
	printf("TEST 14: 255 (FF)\n");
	ft = ft_printf("Mine: %X\n", 255);
	orig = printf("Orig: %X\n", 255);
	check(ft, orig);

	// Test 15: Sıfır Hex
	printf("TEST 15: 0 (Hex)\n");
	ft = ft_printf("Mine: %x\n", 0);
	orig = printf("Orig: %x\n", 0);
	check(ft, orig);

	printf(YELLOW "\n=== POINTER TESTLERİ (%%p) ===\n" RESET);

	// Test 16: Normal Adres
	printf("TEST 16: Değişken Adresi\n");
	ft = ft_printf("Mine: %p\n", &num);
	orig = printf("Orig: %p\n", &num);
	check(ft, orig);

	// Test 17: NULL Pointer
	printf("TEST 17: NULL Pointer\n");
	ft = ft_printf("Mine: %p\n", ptr_null);
	orig = printf("Orig: %p\n", ptr_null);
	check(ft, orig);

	printf(YELLOW "\n=== YÜZDE TESTLERİ (%%%%) ===\n" RESET);

	// Test 18: Yüzde İşareti
	printf("TEST 18: Yüzde (%%)\n");
	ft = ft_printf("Mine: %%\n");
	orig = printf("Orig: %%\n");
	check(ft, orig);

	// Test 19: Karışık
	printf("TEST 19: Karışık Cümle\n");
	ft = ft_printf("Mine: %d%% başarı oranı ile %s!\n", 100, "tamamlandı");
	orig = printf("Orig: %d%% başarı oranı ile %s!\n", 100, "tamamlandı");
	check(ft, orig);

	/* SONUÇ RAPORU */
	printf("\n" YELLOW "==========================================" RESET "\n");
	if (g_errors == 0)
		printf(GREEN "TEBRİKLER! %d TESTİN TAMAMI BAŞARILI! 🚀" RESET "\n", g_tests);
	else
		printf(RED "DİKKAT! TOPLAM %d HATA VAR! ❌" RESET "\n", g_errors);
	printf(YELLOW "==========================================" RESET "\n");

	return (0);
}