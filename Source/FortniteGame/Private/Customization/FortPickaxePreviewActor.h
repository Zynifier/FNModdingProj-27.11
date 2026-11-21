// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/FortCameraFramingTypes.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "Cosmetics/Variants/FortMcpVariantChannelInfo.h"
#include "FrontEnd/CosmeticPreviewInterface.h"
#include "FortPickaxePreviewActor.generated.h"

class AFortWeapon;
class UAnimMontage;
class UAthenaPickaxeItemDefinition;

UCLASS(BlueprintType, Blueprintable)
class AFortPickaxePreviewActor : public AActor, public IFortUICameraFrameTargetInterface, public ICosmeticPreviewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Pickaxe")
	void PreviewPickaxeVariantsApplied(const UAthenaPickaxeItemDefinition* Pickaxe);

protected:
	UFUNCTION(BlueprintPure)
	virtual bool GetUseIASItemPreviewLoadingEvents() const;

	UPROPERTY(EditAnywhere, Category="FortPickaxePreviewActor")
	TObjectPtr<UAnimMontage> MontageToPlayForSwinging;

	UPROPERTY(BlueprintReadOnly, Category="FortPickaxePreviewActor")
	TObjectPtr<UAthenaPickaxeItemDefinition> CosmeticPickaxeItemDefinition;

	UPROPERTY()
	TArray<FMcpVariantChannelInfo> PreviewVariantChannels;

	UPROPERTY(BlueprintReadOnly, Category="FortPickaxePreviewActor")
	TObjectPtr<AFortWeapon> WeaponActor;

	UPROPERTY()
	FFortOnCameraFrameTargetSettingsChangedDelegate OnSettingsChangedDelegate;

	UPROPERTY()
	FFortAthenaLoadout Loadout;

};

