// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "FortControllerStateHandlerComponent.generated.h"

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class VERSEFORTNITEINTERNAL_API UFortControllerStateHandlerComponent : public UControllerComponent
{
	GENERATED_BODY()

public:
	UFortControllerStateHandlerComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION()
	void NotifyOfStateChange(FString& State, bool Active);

};

