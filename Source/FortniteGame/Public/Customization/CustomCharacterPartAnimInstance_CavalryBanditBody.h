// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_CavalryBanditBody.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_CavalryBanditBody : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_CavalryBanditBody")
	FVector FinalGravity;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_CavalryBanditBody")
	float SkydiveSpineSpace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_CavalryBanditBody")
	float SkydiveRootSpace;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_CavalryBanditBody")
	float CrouchRootSpace;

	UPROPERTY(BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_CavalryBanditBody")
	float CrouchSpineSpace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_CavalryBanditBody")
	float FinalRootSpace;

	UPROPERTY(BlueprintReadOnly, Transient, Category="CustomCharacterPartAnimInstance_CavalryBanditBody")
	float FinalSpineSpace;

};

