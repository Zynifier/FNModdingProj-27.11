// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PlayerStateComponent.h"
#include "Quests/IQuestInstanceParticipantInterface.h"
#include "PlayerStateComponent_Quests.generated.h"

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Trigger", "PhysicsVolume"))
class UPlayerStateComponent_Quests : public UPlayerStateComponent, public IQuestInstanceParticipantInterface
{
	GENERATED_BODY()

public:
	UPlayerStateComponent_Quests(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

