// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEventRouterOwnerInterface.generated.h"

class UGameplayEventRouterComponent;

UINTERFACE()
class GAMEPLAYEVENTROUTER_API UGameplayEventRouterOwnerInterface : public UInterface
{
	GENERATED_BODY()
};

class GAMEPLAYEVENTROUTER_API IGameplayEventRouterOwnerInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent)
	TSubclassOf<UGameplayEventRouterComponent> GetEventRouterClass() const;

};

