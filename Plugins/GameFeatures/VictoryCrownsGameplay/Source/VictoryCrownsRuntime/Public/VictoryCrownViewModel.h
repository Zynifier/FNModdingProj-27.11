// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "VictoryCrownViewModel.generated.h"

class UFortControllerComponent_VictoryCrowns;

UCLASS()
class UFortVictoryCrownViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleOnHasWonCrownInMatch();

	UFUNCTION()
	void HandleOnHasWonRoyalRoyale();

	UPROPERTY(BlueprintReadOnly, Category="FortVictoryCrownViewModel", meta=(AllowPrivateAccess="true"))
	int32 BestowedCount;

	UPROPERTY(BlueprintReadOnly, Category="FortVictoryCrownViewModel", meta=(AllowPrivateAccess="true"))
	bool bHasWonCrownInMatch;

	UPROPERTY(BlueprintReadOnly, Category="FortVictoryCrownViewModel", meta=(AllowPrivateAccess="true"))
	bool bHasWonRoyalRoyale;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortControllerComponent_VictoryCrowns> BoundVictoryCrownsComponent;

};

