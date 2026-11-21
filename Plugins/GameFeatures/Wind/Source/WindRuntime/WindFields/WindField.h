// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Field/FieldSystemActor.h"
#include "WindField.generated.h"

class AActor;
class UPrimitiveComponent;
class UShapeComponent;

UCLASS(Abstract)
class AWindField : public AFieldSystemActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddCollider(UShapeComponent* ShapeComponent);

	UFUNCTION(BlueprintCallable)
	void AddIgnoredActor(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	void RemoveCollider(UShapeComponent* ShapeComponent);

	UFUNCTION(BlueprintCallable)
	void RemoveIgnoredActor(AActor* Actor);

	UFUNCTION(BlueprintCallable)
	void SetActive(bool bInIsActive);

	UPROPERTY(BlueprintReadOnly, Transient, Category="WindField")
	float StartTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="WindField", meta=(ExposeOnSpawn="TRUE"))
	float StopTime;

	UPROPERTY(BlueprintReadWrite, Transient, Category="WindField", meta=(ExposeOnSpawn="TRUE"))
	float IncomingDuration;

	UPROPERTY(BlueprintReadWrite, Transient, Category="WindField", meta=(ExposeOnSpawn="TRUE"))
	float OutgoingDuration;

	UPROPERTY(BlueprintReadWrite, Transient, Category="WindField", meta=(ExposeOnSpawn="TRUE"))
	float StrengthMultiplier;

	UPROPERTY(EditAnywhere, Category="WindField")
	bool bIsActive;

protected:
	UFUNCTION()
	virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};

