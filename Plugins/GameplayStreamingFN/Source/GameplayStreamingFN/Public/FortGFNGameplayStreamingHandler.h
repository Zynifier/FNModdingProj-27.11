// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortGameplayStreamingHandler.h"
#include "GFNGameplayStreamingHandler.h"
#include "FortGFNGameplayStreamingHandler.generated.h"

class UFortLocalPlayerAccountHelper;
class UFortOnlineAccount;

UCLASS()
class UFortGFNGameplayStreamingHandler : public UGFNGameplayStreamingHandler, public IFortGameplayStreamingHandler
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortLocalPlayerAccountHelper> FortLocalPlayerAccountHelper;

	UPROPERTY()
	TWeakObjectPtr<UFortOnlineAccount> WeakFortOnlineAccount;

};

