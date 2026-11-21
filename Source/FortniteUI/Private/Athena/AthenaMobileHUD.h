// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaHUDBase.h"
#include "FortUIExtension.h"
#include "AthenaMobileHUD.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaMobileHUD : public UAthenaHUDBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="UI")
	TArray<FUIExtension> TournamentUIExtensions;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TArray<FUIExtension> ArenaTournamentUIExtensions;

};

