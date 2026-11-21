// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortEditorTool_MakeAssetBase.generated.h"

UCLASS(Abstract)
class UFortEditorTool_MakeAssetBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Item Definition", meta=(MustModify))
	FString AssetName;

	UPROPERTY(VisibleAnywhere, Category="Make Item", meta=(MultiLine))
	FString ErrorMessage;

};

