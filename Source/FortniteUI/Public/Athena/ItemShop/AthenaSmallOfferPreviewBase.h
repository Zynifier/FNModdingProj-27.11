// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Item/FortItemBaseWidget.h"
#include "AthenaSmallOfferPreviewBase.generated.h"

class UFortStoreFrontOfferInfo;

UCLASS(MinimalAPI)
class UAthenaSmallOfferPreviewBase : public UFortItemBaseWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortStoreFrontOfferInfo* GetOfferInfo() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnOfferSet();

	UFUNCTION(BlueprintCallable)
	void SetupOffer(UFortStoreFrontOfferInfo* InOfferData);

private:
	UPROPERTY()
	TObjectPtr<UFortStoreFrontOfferInfo> OfferData;

};

