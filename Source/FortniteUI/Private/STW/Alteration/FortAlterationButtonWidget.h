// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortAlterationButtonWidget.generated.h"

class UFortAlterationInfo;

UCLASS(BlueprintType, Blueprintable)
class UFortAlterationButtonWidget : public UCommonButtonLegacy
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortAlterationButtonWidget")
	UFortAlterationInfo* GetAlterationInfo() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortAlterationButtonWidget")
	void OnSetup();

	UFUNCTION(BlueprintCallable, Category="FortAlterationButtonWidget")
	void Setup(UFortAlterationInfo* InAlterationInfo);

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortAlterationInfo> AlterationInfo;

};

