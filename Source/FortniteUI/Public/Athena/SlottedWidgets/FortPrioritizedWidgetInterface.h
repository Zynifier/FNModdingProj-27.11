// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortPrioritizedWidgetInterface.generated.h"

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UFortPrioritizedWidget : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEUI_API IFortPrioritizedWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual bool HasActiveContent() const;

	UFUNCTION(BlueprintCallable)
	virtual void SetHasActiveContent(bool bNewActive);

};

