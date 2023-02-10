CREATE TABLE `pegawai` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `nama` varchar(255),
  `jabatan` varchar(255)
);

CREATE TABLE `rt` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `nomor` int,
  `penduduk_id` int COMMENT 'untuk akun ketua rt',
  `rw_id` int
);

CREATE TABLE `rw` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `nomor` int,
  `penduduk_id` int COMMENT 'untuk akun ketua rw',
  `nama_kp` varchar(255)
);

CREATE TABLE `m_agama` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `nama` varchar(255)
);

CREATE TABLE `m_pekerjaan` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `nama` varchar(255)
);

CREATE TABLE `m_pendidikan` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `nama` varchar(255)
);

CREATE TABLE `m_hub_dgn_kk` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `nama` varchar(255),
  `sequence` int COMMENT 'Urutan untuk menentukan kepala keluarga contoh: 1 kepala keluarga, 2 istri, 3 anak, 4 cucu'
);

CREATE TABLE `penduduk` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `nama` varchar(255),
  `nik` varchar(16),
  `kota_lahir` varchar(255),
  `jenis_kelamin` int(1) COMMENT '1 laki-laki 0 perempuan',
  `alamat_lengkap` varchar(255),
  `tanggal_lahir` date,
  `tanggal_mati` date,
  `asal_data` int(1) COMMENT '0 kelahiran, 1 kedatangan',
  `tanggal_datang` date COMMENT 'di isi jika asal data = '
);

CREATE TABLE `penduduk_akte` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int,
  `dari` date,
  `sampai` date,
  `foto` varchar(255),
  `status` int(1) COMMENT '0 tidak ada, 1 ada'
);

CREATE TABLE `penduduk_ktp` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int,
  `dari` date,
  `sampai` date,
  `foto` varchar(255),
  `status` int(1) COMMENT '0 tidak ada, 1 ada'
);

CREATE TABLE `penduduk_negara` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int,
  `dari` date,
  `sampai` date,
  `negara` int(1) COMMENT '0 wna, 1 wni',
  `negara_nama` varchar(255)
);

CREATE TABLE `penduduk_status_tinggal` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int,
  `dari` date,
  `sampai` date,
  `status` int(1) COMMENT '0 tidak tetap, 1 tetap'
);

CREATE TABLE `penduduk_kawin` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int,
  `dari` date,
  `sampai` date,
  `status` int COMMENT '0 belum kawn 1 kawin 2 cerai hidup 3 cerai mati'
);

CREATE TABLE `penduduk_transaksi` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int,
  `rt_id` int,
  `dari` date,
  `sampai` date,
  `jenis` int COMMENT '1 pindah 2 datang',
  `alamat_lain` varchar(255)
);

CREATE TABLE `penduduk_agama` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int,
  `agama_id` int,
  `dari` date,
  `sampai` date
);

CREATE TABLE `penduduk_pekerjaan` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int,
  `pekerjaan_id` int,
  `dari` date,
  `sampai` date
);

CREATE TABLE `penduduk_pendidikan` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int,
  `pendidikan_id` int,
  `dari` date,
  `sampai` date
);

CREATE TABLE `penduduk_rt` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int,
  `rt_id` int,
  `dari` date,
  `sampai` date
);

CREATE TABLE `penduduk_rw` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int,
  `rt_id` int,
  `rw_id` int,
  `dari` date,
  `sampai` date
);

CREATE TABLE `kartu_keluarga` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `kk_no` int,
  `alamat_lengkap` varchar(255),
  `foto` varchar(255),
  `tanggal_dibuat` date,
  `tanggal_dihapus` date,
  `asal_data` int(1) COMMENT '0 dibuat disini, 1 kedatangan',
  `tanggal_datang` date COMMENT 'di isi jika asal data = '
);

CREATE TABLE `kartu_keluarga_list` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `kk_id` int,
  `penduduk_id` int,
  `dari` date,
  `sampai` date,
  `hub_dgn_kk_id` int
);

CREATE TABLE `kartu_keluarga_rt` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `kk_id` int,
  `rt_id` int,
  `dari` date,
  `sampai` date
);

CREATE TABLE `kartu_keluarga_transaksi` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `kartu_keluarga_id` int,
  `rt_id` int,
  `dari` date,
  `sampai` date,
  `jenis` int COMMENT '1 pindah 2 datang',
  `alamat_lain` varchar(255)
);

CREATE TABLE `tamu` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `nik` varchar(16),
  `rt_id` int,
  `tamu_ke_penduduk_id` int,
  `nama` varchar(255),
  `kota_lahir` varchar(255),
  `tanggal_lahir` date,
  `jenis_kelamin` int(1) COMMENT '1 laki-laki 0 perempuan',
  `status_kawin` int COMMENT '0 belum kawn 1 kawin 2 cerai hidup 3 cerai mati',
  `status_tamu` int COMMENT '0 kontrak, 1 menginap',
  `alamat_lengkap` varchar(255),
  `tanggal_datang` datetime,
  `tanggal_pergi` datetime
);

CREATE TABLE `ps_keterangan` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int COMMENT 'akun yang mengajukan',
  `nomor_surat` varchar(255) COMMENT 'di isi oleh petugas',
  `nama` varchar(255),
  `tempat_lahir` varchar(255),
  `tanggal_lahir` date,
  `jenis_kelamin` int(1) COMMENT '1 laki-laki 0 perempuan',
  `warga_negara` int(1) COMMENT '1 wni 0 wna',
  `nama_negara` varchar(255),
  `agama_id` int,
  `status_kawin` int COMMENT '0 belum kawn 1 kawin 2 cerai hidup 3 cerai mati',
  `pendidikan_id` int,
  `pendidikan_lain` varchar(255),
  `nik` varchar(16),
  `nik_jenis` int COMMENT '1 No KTP, 2 KTP Sementara',
  `rt_id` int,
  `foto_pbb` varchar(255),
  `foto_kk` varchar(255)
);

CREATE TABLE `ps_keterangan_list` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `surat_id` int,
  `keterangan` varchar(255)
);

CREATE TABLE `ps_keterangan_tracking` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `surat_id` int,
  `keterangan` varchar(255),
  `dari_pegawai_id` int,
  `ke_pegawai_id` int,
  `waktu` datetime,
  `status` int COMMENT '1 diserahkan, 2 dikemalikan, 3 selesai, 4 diambil',
  `pihak` int COMMENT '1 penduduk, 2 rt, 3 rw 4 desa'
);

CREATE TABLE `pspk_domisili` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int COMMENT 'akun yang mengajukan',
  `penduduk_db_id` int COMMENT 'Data penduduk yang diajukan jika ada, jika tidak maka nilainya null',
  `nomor_surat` varchar(255) COMMENT 'di isi oleh petugas',
  `nama` varchar(255),
  `tempat_lahir` varchar(255),
  `tanggal_lahir` date,
  `jenis_kelamin` int(1) COMMENT '1 laki-laki 0 perempuan',
  `warga_negara` int(1) COMMENT '1 wni 0 wna',
  `nama_negara` varchar(255),
  `agama_id` int,
  `status_kawin` int COMMENT '0 belum kawn 1 kawin 2 cerai hidup 3 cerai mati',
  `pendidikan_id` int,
  `pendidikan_lain` varchar(255),
  `nik` varchar(16),
  `nik_jenis` int COMMENT '1 No KTP, 2 KTP Sementara',
  `alamat_asal` varchar(255),
  `rt_id` int,
  `rw_id` int
);

CREATE TABLE `pspk_domisili_tracking` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `surat_id` int,
  `keterangan` varchar(255),
  `dari_pegawai_id` int,
  `ke_pegawai_id` int,
  `waktu` datetime,
  `status` int COMMENT '1 diserahkan, 2 dikemalikan, 3 selesai, 4 diambil',
  `pihak` int COMMENT '1 penduduk, 2 rt, 3 rw 4 desa'
);

CREATE TABLE `pspk_pindah` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int COMMENT 'akun yang mengajukan',
  `nomor_surat` varchar(255) COMMENT 'di isi oleh petugas',
  `provinsi` varchar(255),
  `kabupaten_kota` varchar(255),
  `kecamatan` varchar(255),
  `desa_kel` varchar(255),
  `rt_rw` varchar(255),
  `alamat_lengkap` varchar(255),
  `rt_id` int,
  `rw_id` int,
  `alasan_pindah` varchar(255),
  `foto_pbb` varchar(255),
  `foto_kk` varchar(255)
);

CREATE TABLE `pspk_pindah_list` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `surat_id` int,
  `penduduk_db_id` int COMMENT 'Data penduduk yang diajukan jika ada, jika tidak maka nilainya null',
  `nama` varchar(255),
  `tempat_lahir` varchar(255),
  `tanggal_lahir` date,
  `jenis_kelamin` int(1) COMMENT '1 laki-laki 0 perempuan',
  `warga_negara` int(1) COMMENT '1 wni 0 wna',
  `nama_negara` varchar(255),
  `agama_id` int,
  `status_kawin` int COMMENT '0 belum kawn 1 kawin 2 cerai hidup 3 cerai mati',
  `pendidikan_id` int,
  `pendidikan_lain` varchar(255),
  `pekerjaan_id` int,
  `pekerjaan_lain` varchar(255),
  `nik` varchar(16),
  `nik_jenis` int COMMENT '1 No KTP, 2 KTP Sementara',
  `rt_id` int,
  `rw_id` int
);

CREATE TABLE `pspk_pindah_tracking` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `surat_id` int,
  `keterangan` varchar(255),
  `dari_pegawai_id` int,
  `ke_pegawai_id` int,
  `waktu` datetime,
  `status` int COMMENT '1 diserahkan, 2 dikemalikan, 3 selesai, 4 diambil',
  `pihak` int COMMENT '1 penduduk, 2 rt, 3 rw 4 desa'
);

CREATE TABLE `pspk_kelahiran` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int COMMENT 'akun yang mengajukan',
  `nomor_surat` varchar(255) COMMENT 'di isi oleh petugas',
  `anak_nama` varchar(255),
  `anak_tempat_lahir` varchar(255),
  `anak_tanggal_lahir` datetime,
  `anak_jenis_kelamin` int(1) COMMENT '1 laki-laki 0 perempuan',
  `anak_ke` int,
  `anak_berat` double,
  `anak_panjang` double,
  `ibu_penduduk_id` int COMMENT 'Data penduduk yang diajukan jika ada, jika tidak maka nilainya null',
  `ibu_nama` varchar(255),
  `ibu_tempat_lahir` varchar(255),
  `ibu_tanggal_lahir` date,
  `ibu_agama_id` int,
  `ibu_pekerjaan_id` int,
  `ibu_pekerjaan_lain` varchar(255),
  `ayah_penduduk_id` int COMMENT 'Data penduduk yang diajukan jika ada, jika tidak maka nilainya null',
  `ayah_nama` varchar(255),
  `ayah_tempat_lahir` varchar(255),
  `ayah_tanggal_lahir` date,
  `ayah_agama_id` int,
  `ayah_pekerjaan_id` int,
  `ayah_pekerjaan_lain` varchar(255),
  `rt_id` int,
  `rw_id` int,
  `foto_pbb` varchar(255),
  `foto_kk` varchar(255)
);

CREATE TABLE `pspk_kelahiran_tracking` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `surat_id` int,
  `keterangan` varchar(255),
  `dari_pegawai_id` int,
  `ke_pegawai_id` int,
  `waktu` datetime,
  `status` int COMMENT '1 diserahkan, 2 dikemalikan, 3 selesai, 4 diambil',
  `pihak` int COMMENT '1 penduduk, 2 rt, 3 rw 4 desa'
);

CREATE TABLE `pspk_nikah` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int COMMENT 'akun yang mengajukan',
  `nomor_surat` varchar(255) COMMENT 'di isi oleh petugas',
  `ibu_penduduk_id` int COMMENT 'Data penduduk yang diajukan jika ada, jika tidak maka nilainya null',
  `ibu_nama` varchar(255),
  `ibu_tempat_lahir` varchar(255),
  `ibu_tanggal_lahir` date,
  `ibu_warga_negara` int(1) COMMENT '1 wni 0 wna',
  `ibu_nama_negara` varchar(255),
  `ibu_agama_id` int,
  `ibu_pekerjaan_id` int,
  `ibu_pekerjaan_lain` varchar(255),
  `ibu_alamat` varchar(255),
  `ayah_penduduk_id` int COMMENT 'Data penduduk yang diajukan jika ada, jika tidak maka nilainya null',
  `ayah_nama` varchar(255),
  `ayah_tempat_lahir` varchar(255),
  `ayah_tanggal_lahir` date,
  `ayah_warga_negara` int(1) COMMENT '1 wni 0 wna',
  `ayah_nama_negara` varchar(255),
  `ayah_agama_id` int,
  `ayah_pekerjaan_id` int,
  `ayah_pekerjaan_lain` varchar(255),
  `ayah_alamat` varchar(255),
  `waktu` datetime,
  `dengan_seorang` int,
  `calon_a_penduduk_id` int COMMENT 'Data penduduk yang diajukan jika ada, jika tidak maka nilainya null',
  `calon_a_nama` varchar(255),
  `calon_a_tempat_lahir` varchar(255),
  `calon_a_tanggal_lahir` date,
  `calon_a_warga_negara` int(1) COMMENT '1 wni 0 wna',
  `calon_a_nama_negara` varchar(255),
  `calon_a_agama_id` int,
  `calon_a_pendidikan_id` int,
  `calon_a_pendidikan_lain` varchar(255),
  `calon_a_nik` varchar(16),
  `calon_a_nik_jenis` int COMMENT '1 No KTP, 2 KTP Sementara',
  `calon_a_no_kk` varchar(255),
  `calon_a_status_kawin` int COMMENT '0 belum kawn 1 kawin 2 cerai hidup 3 cerai mati',
  `calon_a_pekerjaan_id` int,
  `calon_a_pekerjaan_lain` varchar(255),
  `calon_a_alamat` varchar(255),
  `calon_b_penduduk_id` int COMMENT 'Data penduduk yang diajukan jika ada, jika tidak maka nilainya null',
  `calon_b_nama` varchar(255),
  `calon_b_tempat_lahir` varchar(255),
  `calon_b_tanggal_lahir` date,
  `calon_b_warga_negara` int(1) COMMENT '1 wni 0 wna',
  `calon_b_nama_negara` varchar(255),
  `calon_b_agama_id` int,
  `calon_b_pendidikan_id` int,
  `calon_b_pendidikan_lain` varchar(255),
  `calon_b_nik` varchar(16),
  `calon_b_nik_jenis` int COMMENT '1 No KTP, 2 KTP Sementara',
  `calon_b_no_kk` varchar(255),
  `calon_b_status_kawin` int COMMENT '0 belum kawn 1 kawin 2 cerai hidup 3 cerai mati',
  `calon_b_pekerjaan_id` int,
  `calon_b_pekerjaan_lain` varchar(255),
  `calon_b_alamat` varchar(255),
  `rt_id` int,
  `rw_id` int,
  `foto_pbb` varchar(255),
  `foto_kk` varchar(255)
);

CREATE TABLE `pspk_nikah_tracking` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `surat_id` int,
  `keterangan` varchar(255),
  `dari_pegawai_id` int,
  `ke_pegawai_id` int,
  `waktu` datetime,
  `status` int COMMENT '1 diserahkan, 2 dikemalikan, 3 selesai, 4 diambil',
  `pihak` int COMMENT '1 penduduk, 2 rt, 3 rw 4 desa'
);

CREATE TABLE `pspk_kk` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `penduduk_id` int COMMENT 'akun yang mengajukan',
  `nomor_surat` varchar(255) COMMENT 'di isi oleh petugas',
  `rt_id` int,
  `rw_id` int,
  `alamat_lengkap` varchar(255)
);

CREATE TABLE `pspk_kk_list` (
  `penduduk_id` int COMMENT 'Data penduduk yang diajukan jika ada, jika tidak maka nilainya null',
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `surat_id` int,
  `nama` varchar(255),
  `nik` varchar(16),
  `jenis_kelamin` int(1) COMMENT '1 laki-laki 0 perempuan',
  `tanggal_lahir` date,
  `tempat_lahir` varchar(255),
  `agama_id` int,
  `pendidikan_id` int,
  `pekerjaan_id` int,
  `status_kawin` int COMMENT '0 belum kawn 1 kawin 2 cerai hidup 3 cerai mati',
  `hub_dgn_kk_id` int,
  `calon_b_warga_negara` int(1) COMMENT '1 wni 0 wna',
  `calon_b_nama_negara` varchar(255),
  `no_password` varchar(255),
  `kitas_kitap` varchar(255),
  `ayah_nama` varchar(255),
  `ayah_list_id` int,
  `ibu_nama` varchar(255),
  `ibu_list_id` int
);

CREATE TABLE `pspk_kk_tracking` (
  `id` int PRIMARY KEY AUTO_INCREMENT,
  `surat_id` int,
  `keterangan` varchar(255),
  `dari_pegawai_id` int,
  `ke_pegawai_id` int,
  `waktu` datetime,
  `status` int COMMENT '1 diserahkan, 2 dikemalikan, 3 selesai, 4 diambil',
  `pihak` int COMMENT '1 penduduk, 2 rt, 3 rw 4 desa'
);

ALTER TABLE `rt` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `rt` ADD FOREIGN KEY (`rw_id`) REFERENCES `rw` (`id`);

ALTER TABLE `rw` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `penduduk_akte` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `penduduk_ktp` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `penduduk_negara` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `penduduk_status_tinggal` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `penduduk_kawin` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `penduduk_transaksi` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `penduduk_transaksi` ADD FOREIGN KEY (`rt_id`) REFERENCES `rt` (`id`);

ALTER TABLE `penduduk_agama` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `penduduk_agama` ADD FOREIGN KEY (`agama_id`) REFERENCES `m_agama` (`id`);

ALTER TABLE `penduduk_pekerjaan` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `penduduk_pekerjaan` ADD FOREIGN KEY (`pekerjaan_id`) REFERENCES `m_pekerjaan` (`id`);

ALTER TABLE `penduduk_pendidikan` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `penduduk_pendidikan` ADD FOREIGN KEY (`pendidikan_id`) REFERENCES `m_pendidikan` (`id`);

ALTER TABLE `penduduk_rt` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `penduduk_rt` ADD FOREIGN KEY (`rt_id`) REFERENCES `rt` (`id`);

ALTER TABLE `penduduk_rw` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `penduduk_rw` ADD FOREIGN KEY (`rt_id`) REFERENCES `rt` (`id`);

ALTER TABLE `penduduk_rw` ADD FOREIGN KEY (`rw_id`) REFERENCES `rw` (`id`);

ALTER TABLE `kartu_keluarga_list` ADD FOREIGN KEY (`kk_id`) REFERENCES `kartu_keluarga` (`id`);

ALTER TABLE `kartu_keluarga_list` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `kartu_keluarga_list` ADD FOREIGN KEY (`hub_dgn_kk_id`) REFERENCES `m_hub_dgn_kk` (`id`);

ALTER TABLE `kartu_keluarga_rt` ADD FOREIGN KEY (`kk_id`) REFERENCES `kartu_keluarga` (`id`);

ALTER TABLE `kartu_keluarga_rt` ADD FOREIGN KEY (`rt_id`) REFERENCES `rt` (`id`);

ALTER TABLE `kartu_keluarga_transaksi` ADD FOREIGN KEY (`kartu_keluarga_id`) REFERENCES `kartu_keluarga` (`id`);

ALTER TABLE `kartu_keluarga_transaksi` ADD FOREIGN KEY (`rt_id`) REFERENCES `rt` (`id`);

ALTER TABLE `tamu` ADD FOREIGN KEY (`rt_id`) REFERENCES `rt` (`id`);

ALTER TABLE `tamu` ADD FOREIGN KEY (`tamu_ke_penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `ps_keterangan` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `ps_keterangan` ADD FOREIGN KEY (`agama_id`) REFERENCES `m_agama` (`id`);

ALTER TABLE `ps_keterangan` ADD FOREIGN KEY (`pendidikan_id`) REFERENCES `m_pendidikan` (`id`);

ALTER TABLE `ps_keterangan` ADD FOREIGN KEY (`rt_id`) REFERENCES `rt` (`id`);

ALTER TABLE `ps_keterangan_list` ADD FOREIGN KEY (`surat_id`) REFERENCES `ps_keterangan` (`id`);

ALTER TABLE `ps_keterangan_tracking` ADD FOREIGN KEY (`surat_id`) REFERENCES `ps_keterangan` (`id`);

ALTER TABLE `ps_keterangan_tracking` ADD FOREIGN KEY (`dari_pegawai_id`) REFERENCES `pegawai` (`id`);

ALTER TABLE `ps_keterangan_tracking` ADD FOREIGN KEY (`ke_pegawai_id`) REFERENCES `pegawai` (`id`);

ALTER TABLE `pspk_domisili` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `pspk_domisili` ADD FOREIGN KEY (`penduduk_db_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `pspk_domisili` ADD FOREIGN KEY (`agama_id`) REFERENCES `m_agama` (`id`);

ALTER TABLE `pspk_domisili` ADD FOREIGN KEY (`pendidikan_id`) REFERENCES `m_pendidikan` (`id`);

ALTER TABLE `pspk_domisili` ADD FOREIGN KEY (`rt_id`) REFERENCES `rt` (`id`);

ALTER TABLE `pspk_domisili` ADD FOREIGN KEY (`rw_id`) REFERENCES `rw` (`id`);

ALTER TABLE `pspk_domisili_tracking` ADD FOREIGN KEY (`surat_id`) REFERENCES `pspk_domisili` (`id`);

ALTER TABLE `pspk_domisili_tracking` ADD FOREIGN KEY (`dari_pegawai_id`) REFERENCES `pegawai` (`id`);

ALTER TABLE `pspk_domisili_tracking` ADD FOREIGN KEY (`ke_pegawai_id`) REFERENCES `pegawai` (`id`);

ALTER TABLE `pspk_pindah` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `pspk_pindah` ADD FOREIGN KEY (`rt_id`) REFERENCES `rt` (`id`);

ALTER TABLE `pspk_pindah` ADD FOREIGN KEY (`rw_id`) REFERENCES `rw` (`id`);

ALTER TABLE `pspk_pindah_list` ADD FOREIGN KEY (`surat_id`) REFERENCES `pspk_pindah` (`id`);

ALTER TABLE `pspk_pindah_list` ADD FOREIGN KEY (`penduduk_db_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `pspk_pindah_list` ADD FOREIGN KEY (`agama_id`) REFERENCES `m_agama` (`id`);

ALTER TABLE `pspk_pindah_list` ADD FOREIGN KEY (`pendidikan_id`) REFERENCES `m_pendidikan` (`id`);

ALTER TABLE `pspk_pindah_list` ADD FOREIGN KEY (`pekerjaan_id`) REFERENCES `m_pekerjaan` (`id`);

ALTER TABLE `pspk_pindah_list` ADD FOREIGN KEY (`rt_id`) REFERENCES `rt` (`id`);

ALTER TABLE `pspk_pindah_list` ADD FOREIGN KEY (`rw_id`) REFERENCES `rw` (`id`);

ALTER TABLE `pspk_pindah_tracking` ADD FOREIGN KEY (`surat_id`) REFERENCES `pspk_pindah` (`id`);

ALTER TABLE `pspk_pindah_tracking` ADD FOREIGN KEY (`dari_pegawai_id`) REFERENCES `pegawai` (`id`);

ALTER TABLE `pspk_pindah_tracking` ADD FOREIGN KEY (`ke_pegawai_id`) REFERENCES `pegawai` (`id`);

ALTER TABLE `pspk_kelahiran` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `pspk_kelahiran` ADD FOREIGN KEY (`ibu_penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `pspk_kelahiran` ADD FOREIGN KEY (`ibu_agama_id`) REFERENCES `m_agama` (`id`);

ALTER TABLE `pspk_kelahiran` ADD FOREIGN KEY (`ibu_pekerjaan_id`) REFERENCES `m_pekerjaan` (`id`);

ALTER TABLE `pspk_kelahiran` ADD FOREIGN KEY (`ayah_penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `pspk_kelahiran` ADD FOREIGN KEY (`ayah_agama_id`) REFERENCES `m_agama` (`id`);

ALTER TABLE `pspk_kelahiran` ADD FOREIGN KEY (`ayah_pekerjaan_id`) REFERENCES `m_pekerjaan` (`id`);

ALTER TABLE `pspk_kelahiran` ADD FOREIGN KEY (`rt_id`) REFERENCES `rt` (`id`);

ALTER TABLE `pspk_kelahiran` ADD FOREIGN KEY (`rw_id`) REFERENCES `rw` (`id`);

ALTER TABLE `pspk_kelahiran_tracking` ADD FOREIGN KEY (`surat_id`) REFERENCES `pspk_kelahiran` (`id`);

ALTER TABLE `pspk_kelahiran_tracking` ADD FOREIGN KEY (`dari_pegawai_id`) REFERENCES `pegawai` (`id`);

ALTER TABLE `pspk_kelahiran_tracking` ADD FOREIGN KEY (`ke_pegawai_id`) REFERENCES `pegawai` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`ibu_penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`ibu_agama_id`) REFERENCES `m_agama` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`ibu_pekerjaan_id`) REFERENCES `m_pekerjaan` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`ayah_penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`ayah_agama_id`) REFERENCES `m_agama` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`ayah_pekerjaan_id`) REFERENCES `m_pekerjaan` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`calon_a_penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`calon_a_agama_id`) REFERENCES `m_agama` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`calon_a_pendidikan_id`) REFERENCES `m_pendidikan` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`calon_a_pekerjaan_id`) REFERENCES `m_pekerjaan` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`calon_b_penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`calon_b_agama_id`) REFERENCES `m_agama` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`calon_b_pendidikan_id`) REFERENCES `m_pendidikan` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`calon_b_pekerjaan_id`) REFERENCES `m_pekerjaan` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`rt_id`) REFERENCES `rt` (`id`);

ALTER TABLE `pspk_nikah` ADD FOREIGN KEY (`rw_id`) REFERENCES `rw` (`id`);

ALTER TABLE `pspk_nikah_tracking` ADD FOREIGN KEY (`surat_id`) REFERENCES `pspk_nikah` (`id`);

ALTER TABLE `pspk_nikah_tracking` ADD FOREIGN KEY (`dari_pegawai_id`) REFERENCES `pegawai` (`id`);

ALTER TABLE `pspk_nikah_tracking` ADD FOREIGN KEY (`ke_pegawai_id`) REFERENCES `pegawai` (`id`);

ALTER TABLE `pspk_kk` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `pspk_kk` ADD FOREIGN KEY (`rt_id`) REFERENCES `rt` (`id`);

ALTER TABLE `pspk_kk` ADD FOREIGN KEY (`rw_id`) REFERENCES `rw` (`id`);

ALTER TABLE `pspk_kk_list` ADD FOREIGN KEY (`penduduk_id`) REFERENCES `penduduk` (`id`);

ALTER TABLE `pspk_kk_list` ADD FOREIGN KEY (`surat_id`) REFERENCES `pspk_kk` (`id`);

ALTER TABLE `pspk_kk_list` ADD FOREIGN KEY (`agama_id`) REFERENCES `m_agama` (`id`);

ALTER TABLE `pspk_kk_list` ADD FOREIGN KEY (`pendidikan_id`) REFERENCES `m_pendidikan` (`id`);

ALTER TABLE `pspk_kk_list` ADD FOREIGN KEY (`pekerjaan_id`) REFERENCES `m_pekerjaan` (`id`);

ALTER TABLE `pspk_kk_list` ADD FOREIGN KEY (`ayah_list_id`) REFERENCES `pspk_kk` (`id`);

ALTER TABLE `pspk_kk_list` ADD FOREIGN KEY (`ibu_list_id`) REFERENCES `pspk_kk` (`id`);

ALTER TABLE `pspk_kk_tracking` ADD FOREIGN KEY (`surat_id`) REFERENCES `pspk_kk` (`id`);

ALTER TABLE `pspk_kk_tracking` ADD FOREIGN KEY (`dari_pegawai_id`) REFERENCES `pegawai` (`id`);

ALTER TABLE `pspk_kk_tracking` ADD FOREIGN KEY (`ke_pegawai_id`) REFERENCES `pegawai` (`id`);
