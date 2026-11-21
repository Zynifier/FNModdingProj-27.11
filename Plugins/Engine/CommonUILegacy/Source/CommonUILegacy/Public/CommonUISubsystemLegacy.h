// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUISubsystemBase.h"
#include "CommonUISubsystemLegacy.generated.h"

class UCommonInputManagerLegacy;

UCLASS(meta=(DisplayName="CommonUI"))
class COMMONUILEGACY_API UCommonUISubsystemLegacy : public UCommonUISubsystemBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInputSuspensionChanged, bool, bInputSuspended);

public:
	UFUNCTION(BlueprintPure, Category="CommonUISubsystem")
	UCommonInputManagerLegacy* GetInputManager() const;

	UPROPERTY(BlueprintAssignable, Category="CommonUISubsystem")
	FInputSuspensionChanged OnInputSuspensionChanged;

private:
	UPROPERTY(Transient)
	TObjectPtr<UCommonInputManagerLegacy> CommonInputManager;

};

