// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Camera/FortCameraFramingTypes.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "AthenaPickaxeItemDefinition.generated.h"

class UAnimMontage;
class UFortWeaponMeleeItemDefinition;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaPickaxeItemDefinition : public UAthenaCosmeticItemDefinition, public IFortItemPreviewBoundsInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPickaxeItemDefinition")
	TObjectPtr<UFortWeaponMeleeItemDefinition> WeaponDefinition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Backpack")
	FName MainMeshAttachmentSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Backpack")
	FName OffhandMeshAttachmentSocketName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Backpack")
	FTransform MainMeshRelativeTransform;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Backpack")
	FTransform OffhandMeshRelativeTransform;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Frontend Preview")
	FVector PickaxeImpactFXPreviewOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Frontend Preview")
	FVector PickaxeDualWieldPreviewOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Frontend Preview")
	FRotator PickaxeDualWieldPreviewRotation;

	UPROPERTY(EditAnywhere, Category="Frontend Preview")
	TSoftObjectPtr<UAnimMontage> PreviewIdleMontage;

	UPROPERTY(EditAnywhere, Category="Frontend Preview")
	TSoftObjectPtr<UAnimMontage> PreviewSwingMontage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Frontend Preview|Bounds")
	FFortUICameraFrameTargetBounds CameraFramingBounds;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Frontend Preview|Bounds")
	FVector CameraFramingBoundsCenterOffset;

};

