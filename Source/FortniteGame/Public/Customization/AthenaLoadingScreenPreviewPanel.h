// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatablePanelLegacy.h"
#include "AthenaLoadingScreenPreviewPanel.generated.h"

class UAthenaLoadingScreenItemDefinition;

UCLASS(Abstract, MinimalAPI, BlueprintType, NotBlueprintable, meta=(DisableNativeTick))
class UAthenaLoadingScreenPreviewPanel : public UCommonActivatablePanelLegacy
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UAthenaLoadingScreenItemDefinition> LoadingScreenDefinition;

};

