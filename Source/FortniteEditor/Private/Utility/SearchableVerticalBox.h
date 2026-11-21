// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/VerticalBox.h"
#include "SearchableVerticalBox.generated.h"

UCLASS(meta=(ShortTooltip="A layout panel for automatically laying child widgets out vertically with a search function"))
class FORTNITEEDITOR_API USearchableVerticalBox : public UVerticalBox
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void UpdateSearchableChildren(const FString& SearchString);

};

