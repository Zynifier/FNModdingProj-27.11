// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "FabricWidgetComponent.generated.h"

UCLASS(HideCategories=("Object", "Activation", "Components|Activation", "Sockets", "Base", "Lighting", "LOD", "Mesh", "Mobility", "Trigger"), ClassGroup=("Fabric"), meta=(BlueprintSpawnableComponent))
class FABRICUI_API UFabricWidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	ETickMode GetTickMode() const;

	UFUNCTION(BlueprintCallable)
	void SetShouldSuscribeToSignificanceSubsystem(bool ShouldSuscribe);

private:
	UPROPERTY()
	bool bShouldSuscribeToSignificanceSubsystem;

};

