// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCustomPartTypeEnum.h"
#include "FortCharacterPartMontageInfo.generated.h"

class UAnimMontage;

USTRUCT(BlueprintType)
struct FFortCharacterPartMontageInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	TEnumAsByte<EFortCustomPartType::Type> CharacterPart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Animation")
	TObjectPtr<UAnimMontage> AnimMontage;

};

