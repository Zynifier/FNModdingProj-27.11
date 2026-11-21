// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TimerHandle.h"
#include "FortMaterialStyleComponent.generated.h"

class UFortMaterialStyle;
class UFortMaterialStyleSet;
class UMaterialInstanceDynamic;
enum class EStyleRequestArbitrationPolicy : uint8;

UENUM()
enum class EStyleRequestArbitrationPolicy : uint8
{
	// Request should immediately replace any existing request + clear queued requests

	ReplaceActive = 0,
	// Request should be queued behind other pending style requests

	QueueBack = 1,
	// Request should be queued, but ahead of other pending style requests

	QueueFront = 2,
};

UENUM()
enum class EStyleSpecificationMethod : uint8
{
	// Request specifies style via lookup from style set via style name 

	StyleSetLookup = 0,
	// Request specifies direct MaterialStyle object reference

	DirectReference = 1,
};

USTRUCT(BlueprintType)
struct FRequestStyleParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Duration")
	float DurationOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StyleDetails")
	TObjectPtr<UMaterialInstanceDynamic> MaterialInstanceDynamic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StyleDetails")
	EStyleSpecificationMethod StyleSpecificationMethod;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StyleDetails")
	TObjectPtr<UFortMaterialStyleSet> StyleSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StyleDetails")
	FName StyleName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StyleDetails")
	TObjectPtr<UFortMaterialStyle> DirectStyleReference;

};

USTRUCT(BlueprintType)
struct FActiveStyleInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ActiveStyleInfo")
	TObjectPtr<UFortMaterialStyle> PreviousStyle;

	UPROPERTY(BlueprintReadOnly, Category="ActiveStyleInfo")
	TObjectPtr<UFortMaterialStyle> CurrentStyle;

	UPROPERTY(BlueprintReadOnly, Category="ActiveStyleInfo")
	FRequestStyleParams CurrentStyleRequest;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPrepareForNewStyleActivation, const FActiveStyleInfo&, StyleToBeActivated);

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class UFortMaterialStyleComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const FActiveStyleInfo& GetActiveStyleInfo() const;

	UFUNCTION(BlueprintPure)
	UMaterialInstanceDynamic* GetDynamicMaterialInstance() const;

	UFUNCTION(BlueprintCallable, BlueprintCosmetic)
	void RequestStyleChange(const FRequestStyleParams& Request, const EStyleRequestArbitrationPolicy RequestArbitrationPolicy = EStyleRequestArbitrationPolicy::ReplaceActive);

	UPROPERTY(EditDefaultsOnly, Category="DefaultStyle")
	bool bDefaultStyleEnabled;

	UPROPERTY(EditDefaultsOnly, Category="DefaultStyle", meta=(editCondition="bDefaultStyleEnabled"))
	TObjectPtr<UFortMaterialStyleSet> DefaultStyleSet;

	UPROPERTY(EditDefaultsOnly, Category="DefaultStyle", meta=(editCondition="bDefaultStyleEnabled"))
	FName DefaultStyleName;

	UPROPERTY(EditDefaultsOnly, Category="Behaviour", meta=(editCondition="bDefaultStyleEnabled"))
	float FiniteStyleDuration;

	UPROPERTY(EditDefaultsOnly, Category="Material", meta=(editCondition="bDefaultStyleEnabled"))
	FName DynamicMaterialSlotName;

	UPROPERTY(BlueprintAssignable)
	FOnPrepareForNewStyleActivation OnPrepareForNewStyleActivation;

private:
	UPROPERTY(Transient)
	TArray<FRequestStyleParams> PendingRequestQueue;

	UPROPERTY(Transient)
	FActiveStyleInfo ActiveStyleInfo;

	UPROPERTY(Transient)
	FTimerHandle ProcessRequestQueueTimerHandle;

	UPROPERTY(Transient)
	FRequestStyleParams DefaultStyleRequest;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> DynamicMaterialInstance;

};

