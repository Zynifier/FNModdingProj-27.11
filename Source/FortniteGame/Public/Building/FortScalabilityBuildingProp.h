// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp.h"
#include "FortScalabilityBuildingProp.generated.h"

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class AFortScalabilityBuildingProp : public ABuildingProp
{
	GENERATED_BODY()

protected:
	UFUNCTION(meta=(CallInEditor="true"))
	void HandleAntiAliasingQualityChanged();

	UFUNCTION(meta=(CallInEditor="true"))
	void HandleEffectsQualityChanged();

	UFUNCTION(meta=(CallInEditor="true"))
	void HandleGlobalIlluminationQualityChanged();

	UFUNCTION(meta=(CallInEditor="true"))
	void HandlePostProcessQualityChanged();

	UFUNCTION(meta=(CallInEditor="true"))
	void HandleReflectionQualityChanged();

	UFUNCTION(meta=(CallInEditor="true"))
	void HandleShadowQualityChanged();

	UFUNCTION(meta=(CallInEditor="true"))
	void HandleTextureQualityChanged();

	UFUNCTION(meta=(CallInEditor="true"))
	void HandleViewDistanceQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnAntiAliasingQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnEffectsQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnGlobalIlluminationQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnPostProcessQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnReflectionQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnShadowQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnTextureQualityChanged();

	UFUNCTION(BlueprintImplementableEvent, Category="Scalability", meta=(CallInEditor="true"))
	void OnViewDistanceQualityChanged();

};

