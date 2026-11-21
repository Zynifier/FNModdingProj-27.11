// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/CustomCharacterPartAnimInstance.h"
#include "CustomCharacterPartAnimInstance_Alter_Ego_Pack_F.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UCustomCharacterPartAnimInstance_Alter_Ego_Pack_F : public UCustomCharacterPartAnimInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Alter_Ego_Pack_F")
	float BackpackTransformAlpha;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="CustomCharacterPartAnimInstance_Alter_Ego_Pack_F")
	float SkydiveDynamicsAlpha;

};

