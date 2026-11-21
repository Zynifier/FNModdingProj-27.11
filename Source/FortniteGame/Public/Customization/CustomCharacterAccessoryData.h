// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Customization/CustomCharacterPartData.h"
#include "CustomCharacterAccessoryData.generated.h"

class UAnimInstance;
class UCustomAccessoryAttachmentData;
class UCustomAccessoryColorSwatch;

USTRUCT()
struct FCustomAccessoryMorphs
{
	GENERATED_BODY()

};

USTRUCT()
struct FCustomAccessoryHatReactiveMorphs : public FCustomAccessoryMorphs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HatMorphs")
	TArray<FName> CapMorphTargets;

	UPROPERTY(EditAnywhere, Category="HatMorphs")
	TArray<FName> HelmetMorphTargets;

	UPROPERTY(EditAnywhere, Category="HatMorphs")
	TArray<FName> MaskMorphTargets;

	UPROPERTY(EditAnywhere, Category="HatMorphs")
	TArray<FName> HatMorphTargets;

};

UCLASS()
class UCustomCharacterAccessoryData : public UCustomCharacterPartData
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Accessory")
	FName AttachSocketName;

	UPROPERTY(EditAnywhere, Category="Accessory")
	FVector AttachOffset;

	UPROPERTY(EditDefaultsOnly, Category="Accessory")
	TObjectPtr<UCustomAccessoryAttachmentData> AttachmentOverrideData;

	UPROPERTY(EditAnywhere, Category="Accessory")
	bool bUseClothCollisionFromOtherParts;

	UPROPERTY(EditAnywhere, Category="Accessory", meta=(DisplayName="Collide With Other Part's Cloth"))
	bool bCollideWithOtherPartsCloth;

	UPROPERTY(EditAnywhere, Category="Accessory")
	TSoftClassPtr<UAnimInstance> AnimClass;

	UPROPERTY(EditAnywhere, Category="Accessory")
	TSoftClassPtr<UAnimInstance> FrontEndAnimClass;

	UPROPERTY(EditAnywhere, Category="Accessory")
	TSoftClassPtr<UAnimInstance> MannequinAnimClass;

	UPROPERTY(EditAnywhere, Category="Accessory")
	TSoftObjectPtr<UCustomAccessoryColorSwatch> AccessoryColors;

};

