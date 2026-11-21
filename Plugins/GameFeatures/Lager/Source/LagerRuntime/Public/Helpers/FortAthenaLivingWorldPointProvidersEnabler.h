// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortAthenaLivingWorldPointProvidersEnabler.generated.h"

class IFortAthenaLivingWorldPointProviderInterface;

UCLASS()
class AFortAthenaLivingWorldPointProvidersEnabler : public AActor
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCompletedEvaluation, const TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>>&, EnabledPointProviders);

public:
	UFUNCTION(BlueprintPure)
	bool DoesStartEnabled() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void EvaluateAndEnablePointProviders();

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	const TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>>& GetEnabledLinkedPointProviders() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	const FGameplayTagContainer& GetEnablerTags() const;

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool HasCompletedEvaluation() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RemoveClosestPointProvidersToPoint(const FVector& Point, const float MaximumDistance, const int32 PointsToDisable);

protected:
	UPROPERTY(Transient)
	TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>> EnabledLinkedPointProviders;

	UPROPERTY(Transient)
	TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>> AvailableLinkedPointProviders;

private:
	UFUNCTION()
	void OnCurrentPlaylistLoaded(FName PlaylistName, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LivingWorld", meta=(AllowPrivateAccess))
	FGameplayTagContainer EnablerTags;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	TArray<TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>> LinkedPointProviders;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	FScalableFloat PointProvidersToEnable;

	UPROPERTY(EditAnywhere, Category="LivingWorld")
	FScalableFloat EvaluateAutomatically;

	UPROPERTY(BlueprintAssignable, meta=(AllowPrivateAccess="true"))
	FOnCompletedEvaluation OnCompletedEvaluationDelegate;

};

