// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortLocalizationServiceTypes.h"
#include "FortControllerComponent_LocalizationService.generated.h"

UCLASS()
class UFortControllerComponent_LocalizationService : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable)
	void ServerUpdateLocale(const FString& InLocale);

protected:
	UFUNCTION()
	void OnRep_LocalizationDocument();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LocalizationDocument)
	FReplicatedLocalizedDocument LocalizationDocument;

};

