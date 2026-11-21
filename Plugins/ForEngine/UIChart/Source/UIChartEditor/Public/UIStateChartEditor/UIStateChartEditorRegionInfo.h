// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UIStateChartEditorRegionInfo.generated.h"

class UUIStateChartEditorStateInfo;

UCLASS()
class UICHARTEDITOR_API UUIStateChartEditorRegionInfo : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UUIStateChartEditorStateInfo> RootState;

	UPROPERTY(Transient)
	TArray<UUIStateChartEditorStateInfo*> StateInfoList;

};

