// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Context/FortStoreContext.h"
#include "StoreToastRequest.generated.h"

class UCatalogMessaging;

UCLASS(BlueprintType)
class UStoreToastRequest : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void BeginRequest();

	UFUNCTION(BlueprintCallable)
	virtual void CompleteRequest();

	UFUNCTION(BlueprintPure)
	FStoreCallout GetToast() const;

	UFUNCTION(BlueprintCallable)
	virtual bool IsRequestReady();

	UFUNCTION(BlueprintCallable)
	virtual bool ShouldBeginRequest();

	UFUNCTION(BlueprintCallable)
	virtual void SkipRequest();

private:
	UPROPERTY(Transient)
	TObjectPtr<UCatalogMessaging> CatalogMessaging;

};

