// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/HeadPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_SlurpLegendsBase.generated.h"

class UMaterialInstanceDynamic;

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_SlurpLegendsBase : public UHeadPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_SlurpLegendsBase")
	float MorphBlendAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_SlurpLegendsBase")
	TObjectPtr<UMaterialInstanceDynamic> PartMID;

};

