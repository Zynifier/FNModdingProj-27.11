// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortWeaponComponent_TargetModeSelector.h"
#include "FortWeaponComponent_TargetModeSelector_Zoom.generated.h"

class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FMaterialParamterLerpInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MaterialParamterLerpInfo")
	TWeakObjectPtr<UMaterialInstanceDynamic> MaterialInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MaterialParamterLerpInfo")
	FName PropertyName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MaterialParamterLerpInfo")
	float StartValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MaterialParamterLerpInfo")
	float EndValue;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortWeaponComponent_TargetModeSelector_Zoom : public UFortWeaponComponent_TargetModeSelector
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetScopeCameraOffset(const float ScopeSizeConstant, const float DefautFOV, const float DefaultScopeOffset) const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void LerpScopeMaterialParameters(const float Alpha) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortWeaponComponent_TargetModeSelector_Zoom")
	TArray<FMaterialParamterLerpInfo> MaterialLerpInfo;

};

