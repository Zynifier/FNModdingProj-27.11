// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortCreativePropertyEditorEventBindingDialogListItemProxy.generated.h"

UCLASS(BlueprintType)
class UFortCreativePropertyEditorEventBindingDialogListItemProxy : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const FText& GetDisplayName(const bool bFormatted) const;

};

