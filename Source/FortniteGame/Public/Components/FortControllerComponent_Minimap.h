// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_Minimap.generated.h"

class UFortMiniMapInputComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnToggleFullscreenMap, bool, bFullscreenMapVisible);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_Minimap : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Map")
	void HideFullScreenMap();

	UFUNCTION(BlueprintPure, Category="Map")
	virtual bool IsFullscreenMapVisible() const;

	UFUNCTION(BlueprintCallable, Category="Map")
	void OpenFullScreenMapTab(const FName TabId);

	UFUNCTION(BlueprintCallable, Category="Map")
	virtual void ToggleFullScreenMap();

	UPROPERTY(BlueprintAssignable, Category="PlayerController")
	FOnToggleFullscreenMap OnToggleFullscreenMap;

protected:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortMiniMapInputComponent> MiniMapInputComponent;

};

