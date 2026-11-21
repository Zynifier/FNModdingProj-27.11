// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortAlterationWidget.generated.h"

class UFortAlterationInfo;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortAlterationWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortAlterationWidget")
	UFortAlterationInfo* GetAlterationInfo() const;

	UFUNCTION(BlueprintImplementableEvent, Category="FortAlterationWidget")
	void OnSetup();

	UFUNCTION(BlueprintCallable, Category="FortAlterationWidget")
	void Setup(UFortAlterationInfo* InAlterationInfo);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAlterationWidget")
	float MaxPipCount;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortAlterationInfo> AlterationInfo;

};

