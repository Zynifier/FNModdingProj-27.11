// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "Athena/ItemShop/ReloadMtx/AthenaStaticMtxOfferButtonLegacy.h"
#include "AthenaMtxOfferListEntryButtonLegacy.generated.h"

UCLASS(Abstract)
class UAthenaMtxOfferListEntryButtonLegacy : public UAthenaStaticMtxOfferButtonLegacy, public IUserObjectListEntry
{
	GENERATED_BODY()

};

