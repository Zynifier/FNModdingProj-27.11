// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortAnimTypes.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "HeadPartAnimInstance.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UHeadPartAnimInstance : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FacialAnim")
	FFortAnimInput_Facial FacialInput;

	UPROPERTY(BlueprintReadOnly, Transient, Category="HeadPartAnimInstance")
	float FaceIdleAlpha;

	UPROPERTY(BlueprintReadOnly, Transient, Category="HeadPartAnimInstance")
	bool bIs3LAnim;

	UPROPERTY(BlueprintReadOnly, Transient, Category="HeadPartAnimInstance")
	bool bIsFaceBoneAnim;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="HeadPartAnimInstance")
	bool bIs3LRig;

};

