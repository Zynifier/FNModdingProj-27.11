// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SValkyrieNews.generated.h"

UCLASS()
class UProjectPickerWrapper : public UUserWidget
{
	GENERATED_BODY()

public:
	UProjectPickerWrapper(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Project Browser")
	void CloseProjectBrowser() const;

};

