// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MotdActionBase.generated.h"

class AFortPlayerController;

UCLASS(Abstract, BlueprintType)
class FORTNITEUI_API UMotdActionBase : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void CallToAction(AFortPlayerController* PlayerController);

	UFUNCTION(BlueprintPure)
	bool ShouldCloseWidget() const;

};

