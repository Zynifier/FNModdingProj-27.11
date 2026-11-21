// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "FortAthenaAIBotCharacterCustomization.generated.h"

UCLASS(EditInlineNew, BlueprintType, Blueprintable)
class UFortAthenaAIBotCharacterCustomization : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="CharacterCustomization", meta=(AllowPrivateAccess="true"))
	FFortAthenaLoadout CustomizationLoadout;

};

