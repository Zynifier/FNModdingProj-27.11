// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "Quests/IFortQuestInstanceManagerInterface.h"
#include "FortControllerComponent_FrontendQuests.generated.h"

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_FrontendQuests : public UControllerComponent, public IFortQuestInstanceManagerInterface
{
	GENERATED_BODY()

public:
	UFortControllerComponent_FrontendQuests(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

