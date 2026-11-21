// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "FortConversationSubsystem.generated.h"

class UFortNonPlayerConversationParticipantComponent;

UCLASS(MinimalAPI)
class UFortConversationSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortNonPlayerConversationParticipantComponent>> Participants;

};

