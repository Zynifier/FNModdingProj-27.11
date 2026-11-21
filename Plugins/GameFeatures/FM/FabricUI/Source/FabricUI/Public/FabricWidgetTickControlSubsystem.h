// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "FabricWidgetTickControlSubsystem.generated.h"

class UFabricWidgetComponent;

UCLASS()
class FABRICUI_API UFabricWidgetTickControlSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void RegisterFabricWidgetComponent(UFabricWidgetComponent* WidgetComponent);

	UFUNCTION(BlueprintCallable)
	void UnregisterFabricWidgetComponent(UFabricWidgetComponent* WidgetComponent);

};

