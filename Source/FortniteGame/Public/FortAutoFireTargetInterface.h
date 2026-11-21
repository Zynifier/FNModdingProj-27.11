// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortAutoFireTargetInterface.generated.h"

class AActor;

UINTERFACE(MinimalAPI, BlueprintType, Blueprintable)
class UFortAutoFireTargetInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortAutoFireTargetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="AutofireInterface")
	bool IsValidAutoFireTarget(const AActor* Attacker) const;

};

