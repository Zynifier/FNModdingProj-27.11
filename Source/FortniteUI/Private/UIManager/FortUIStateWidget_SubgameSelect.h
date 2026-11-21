// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortUIStateWidget_NUI.h"
#include "FortUIStateWidget_SubgameSelect.generated.h"

enum class ESubGame : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(Category="Fortnite UI"))
class UFortUIStateWidget_SubgameSelect : public UFortUIStateWidget_NUI
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleSubGameChanged(ESubGame NewSubGame);

};

