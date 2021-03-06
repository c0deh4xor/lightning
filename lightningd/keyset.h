#ifndef LIGHTNING_LIGHTNINGD_KEYSET_H
#define LIGHTNING_LIGHTNINGD_KEYSET_H
#include "config.h"
#include <bitcoin/pubkey.h>
#include <stdbool.h>

/* Keys needed to derive a particular commitment tx. */
struct keyset {
	struct pubkey self_revocation_key;
	struct pubkey self_delayed_payment_key;
	struct pubkey self_payment_key, other_payment_key;
};

bool derive_keyset(const struct pubkey *per_commitment_point,
		   const struct pubkey *self_payment_basepoint,
		   const struct pubkey *other_payment_basepoint,
		   const struct pubkey *self_delayed_basepoint,
		   const struct pubkey *other_revocation_basepoint,
		   struct keyset *keyset);
#endif /* LIGHTNING_LIGHTNINGD_KEYSET_H */
