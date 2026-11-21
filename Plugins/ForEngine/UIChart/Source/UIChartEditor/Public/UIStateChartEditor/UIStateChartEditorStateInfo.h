// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UIStateChartEditorStateInfo.generated.h"

class UUIStateConfiguration;

UCLASS()
class UICHARTEDITOR_API UUIStateChartEditorStateInfo : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIStateConfiguration> StateConfiguration;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUIStateConfiguration> StateRegionRoot;

	UPROPERTY(Transient)
	FString DisplayPath;

};

