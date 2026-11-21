// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "IconTextButtonSpectatorBase.generated.h"

UCLASS(Abstract)
class UIconTextButtonSpectatorBase : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetText(const FText& Text);

};

