// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayInteractionSmartObjectBehaviorDefinition.h"
#include "FortGameplayInteractionSmartObjectBehaviorDefinition.generated.h"

class AActor;

UCLASS(BlueprintType, Blueprintable)
class UFortGameplayInteractionSmartObjectBehaviorDefinition : public UGameplayInteractionSmartObjectBehaviorDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool CanBeUsedBy(const AActor* User, const AActor* SmartObjectActor) const;

};

