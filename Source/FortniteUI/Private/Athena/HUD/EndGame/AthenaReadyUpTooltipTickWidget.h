// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "AthenaReadyUpTooltipTickWidget.generated.h"

class UFortPartyMember;

UCLASS(Abstract, BlueprintType, meta=(DisableNativeTick))
class UAthenaReadyUpTooltipTickWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReadinessChanged, bool, bIsReadied);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnSetPartyMember(UFortPartyMember* NewPartyMember);

private:
	UPROPERTY(BlueprintAssignable, Category="IGM", meta=(AllowPrivateAccess="true"))
	FOnReadinessChanged OnReadinessChangedDelegate;

	UPROPERTY(Transient)
	TObjectPtr<UFortPartyMember> CachedPartyMember;

};

