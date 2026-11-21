// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Curie/FortCurieTypes.h"
#include "CurieMinimalTypes.h"
#include "FortCurieInteractionComponent.generated.h"

class AActor;
class UObject;
class UPrimitiveComponent;

UENUM(BlueprintType)
enum class EFortCurieApplicationEvent : uint8
{
	OnHit = 0,
	OnBeginOverlap = 1,
	OnEndOverlap = 2,
	MaxValue = 3 UMETA(Hidden),
};

UENUM(BlueprintType)
enum class EFortCurieExecutionType : uint8
{
	Application = 0,
	Interaction = 1,
};

USTRUCT(BlueprintType)
struct FFortCurieExecutionFilter
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCurieExecutionFilter", meta=(Categories="Curie.State"))
	FGameplayTag RequiredState;

};

USTRUCT(BlueprintType)
struct FFortCurieExecutionEntry
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCurieExecutionEntry")
	EFortCurieExecutionType ExecutionType;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieExecutionEntry", meta=(EditCondition="EFortCurieExecutionType::Application == ExecutionType"))
	EFortCurieApplicationEvent ApplicationEvent;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieExecutionEntry")
	FFortCurieExecutionFilter ExecutionFilter;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieExecutionEntry")
	FFortCurieExecutionParams ExecutionParameters;

};

USTRUCT()
struct FFortInteractionExecutionInteractData
{
	GENERATED_BODY()

};

UCLASS(ClassGroup=("Curie"), meta=(BlueprintSpawnableComponent))
class UFortCurieInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RegisterCollisionComponent(UPrimitiveComponent* InCollisionComponent);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void UnregisterCollisionComponent();

private:
	UFUNCTION()
	void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void HandleEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void HandleHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void OnCurieStateAttached(UObject* Owner, FCurieContainerHandle ContainerHandle, const FGameplayTag& StateIdentifier);

	UFUNCTION()
	void OnCurieStateDetached(UObject* Owner, FCurieContainerHandle ContainerHandle, const FGameplayTag& StateIdentifier);

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> CollisionComponent;

	UPROPERTY(EditDefaultsOnly, Category="FortCurieInteractionComponent")
	TArray<FFortCurieExecutionEntry> ExecutionEntries;

};

