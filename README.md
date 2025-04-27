## Sistem Deteksi Jarak dan Pencahayaan untuk Peringatan Dini
Proyek ini merupakan implementasi sistem peringatan dini berbasis mikrokontroler STM32. Sistem ini dirancang untuk meningkatkan keselamatan dengan mendeteksi objek di depan kendaraan serta mendeteksi kondisi pencahayaan, dan mengaktifkan alarm (buzzer dan LED) sebagai sinyal peringatan otomatis.

## Komponen Utama
  - STM32F446RE – Mikrokontroler sebagai pusat kontrol dan pemrosesan logika.
  - Sensor Ultrasonik (HC-SR04) – Mengukur jarak objek di depan kendaraan.
  - Sensor LDR (Light Dependent Resistor) – Mendeteksi intensitas pencahayaan lingkungan.
  - Buzzer – Memberikan peringatan suara saat kondisi kritis terdeteksi.
  - LED – Memberikan indikator visual sebagai peringatan tambahan.
  - Power Supply – Mengalirkan daya ke sistem (3.3V/5V untuk mikrokontroler, buzzer, dan LED).

## Cara Kerja Sistem
1.	Sensor ultrasonik memantau jarak kendaraan dengan objek di depan.
2.	Sensor LDR memantau intensitas cahaya di lingkungan sekitar.
3.	STM32F446RE memproses data dari kedua sensor secara real-time.
4.	Jika kondisi kritis terpenuhi (jarak terlalu dekat dan pencahayaan terlalu rendah), sistem akan:
     - Mengaktifkan LED untuk memberikan indikator visual.
     - Mengaktifkan Buzzer untuk memberikan peringatan suara.
5.	Sistem akan menonaktifkan LED dan buzzer secara otomatis jika kondisi kembali aman.
