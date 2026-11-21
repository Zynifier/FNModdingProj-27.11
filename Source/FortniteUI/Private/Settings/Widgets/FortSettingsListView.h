// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ListView.h"
#include "FortSettingsListView.generated.h"

class UFortSettingVisualData;

UCLASS()
class UFortSettingsListView : public UListView
{
	GENERATED_BODY()

public:
	UFortSettingsListView(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(EditAnywhere, Category="FortSettingsListView")
	TObjectPtr<UFortSettingVisualData> VisualData;

};

