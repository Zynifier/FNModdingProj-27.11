// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MetasoundOfflinePlayerComponent.generated.h"

class UMetaSoundSource;

UCLASS()
class HARMONIXMETASOUND_API UMetasoundOfflinePlayerComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UMetaSoundSource> MetasoundSource;

};

