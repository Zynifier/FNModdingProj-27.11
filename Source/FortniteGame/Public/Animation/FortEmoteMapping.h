// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCustomBodyTypeEnum.h"
#include "FortGender.h"
#include "FortEmoteMapping.generated.h"

class UAnimMontage;

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct FFortEmoteMapping
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortEmoteMapping")
	TEnumAsByte<EFortCustomBodyType::Type> BodyType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortEmoteMapping")
	TEnumAsByte<EFortCustomGender::Type> Gender;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortEmoteMapping")
	TSoftObjectPtr<UAnimMontage> EmoteMontage;

};

