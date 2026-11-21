// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CosmeticsEventTypes.h"
#include "CosmeticsEventRegistrar.generated.h"

class ICosmeticsEventRegistrar;

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FCosmeticsEventTargetDynamicDelegate, const TScriptInterface<ICosmeticsEventRegistrar>&, EventTarget);

UINTERFACE(BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class COSMETICSFRAMEWORKEVENTS_API UCosmeticsEventRegistrar : public UInterface
{
	GENERATED_BODY()
};

class COSMETICSFRAMEWORKEVENTS_API ICosmeticsEventRegistrar
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(DisplayName="Register On Cosmetic Application Completed"))
	virtual FCosmeticsEventHandle RegisterOnCosmeticApplicationCompleted_BP(const FCosmeticsEventTargetDynamicDelegate& Delegate, int32 Flags = 0);

};

